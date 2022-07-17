#ifndef ALGORITHMIC_MATH_BM_BM_PRIME_H_
#define ALGORITHMIC_MATH_BM_BM_PRIME_H_

#include <vector>

namespace algorithmic::math {

template <int N>
class BMPrime {
    using ll = int64_t;
    using VI = std::vector<ll>;

public:
    struct Options {
        ll mod{ll(1e9) + 7};
    };

    class Builder {
    public:
        Builder &WithMod(ll mod) {
            options_.mod = mod;
            return *this;
        }

        BMPrime<N> Build() {
            return BMPrime<N>(options_);
        }

    private:
        Options options_;
    };

public:
    BMPrime(Options options = Options()) : options_(options) {
        mod = options_.mod;
    }

    ll Gao(VI a, ll n) {
        VI c = bm(a);
        c.erase(c.begin());

        for (ll i = 0; i < ll(c.size()); i++) {
            c[i] = (mod - c[i]) % mod;
        }

        return solve(n, c, VI(a.begin(), a.begin() + int(c.size())));
    }

private:
    ll powMod(ll a, ll b) {
        ll res = 1;
        a %= mod;
        assert(b >= 0);

        for (; b; b >>= 1) {
            if (b & 1) {
                res = res * a % mod;
            }

            a = a * a % mod;
        }

        return res;
    }

    void mul(ll *a, ll *b, ll k) {
        for (ll i = 0; i < k + k; i++) {
            _c[i] = 0;
        }

        for (ll i = 0; i < k; i++) {
            if (a[i]) {
                for (int j = 0; j < k; j++) {
                    _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
                }
            }
        }

        for (ll i = k + k - 1; i >= k; i--) {
            if (_c[i]) {
                for (ll j = 0; j < ll(Md.size()); j++) {
                    _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
                }
            }
        }

        for (ll i = 0; i < k; i++) {
            a[i] = _c[i];
        }
    }

    // a 系数 b 初值
    // b[n+1] = a[0] * b[n] + ...
    ll solve(ll n, VI a, VI b) {
        ll ans = 0;
        ll pnt = 0;
        ll k = ll(a.size());

        assert(a.size() == b.size());

        for (ll i = 0; i < k; i++) {
            _md[k - 1 - i] = -a[i];
        }

        _md[k] = 1;
        Md.clear();

        for (ll i = 0; i < k; i++) {
            if (_md[i] != 0) {
                Md.push_back(i);
            }
        }

        for (ll i = 0; i < k; i++) {
            res[i] = base[i] = 0;
        }

        res[0] = 1;

        while ((1ll << pnt) <= n) {
            pnt++;
        }

        for (ll p = pnt; p >= 0; p--) {
            mul(res, res, k);
            if ((n >> p) & 1) {
                for (ll i = k - 1; i >= 0; i--) {
                    res[i + 1] = res[i];
                }

                res[0] = 0;

                for (ll j = 0; j < ll(Md.size()); j++) {
                    res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
                }
            }
        }

        for (ll i = 0; i < k; i++) {
            ans = (ans + res[i] * b[i]) % mod;
        }

        if (ans < 0) {
            ans += mod;
        }

        return ans;
    }

    VI bm(VI s) {
        VI C(1, 1), B(1, 1);
        ll L = 0, m = 1, b = 1;

        for (ll n = 0; n < ll(s.size()); n++) {
            ll d = 0;

            for (ll i = 0; i < L + 1; i++) {
                d = (d + (ll)C[i] * s[n - i]) % mod;
            }

            if (d == 0) {
                ++m;
            } else if (2 * L <= n) {
                VI T = C;
                ll c = mod - d * powMod(b, mod - 2) % mod;

                while (C.size() < B.size() + m) {
                    C.push_back(0);
                }

                for (ll i = 0; i < ll(B.size()); i++) {
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                }

                L = n + 1 - L;
                B = T;
                b = d;
                m = 1;
            } else {
                ll c = mod - d * powMod(b, mod - 2) % mod;
                while (C.size() < B.size() + m) {
                    C.push_back(0);
                }

                for (ll i = 0; i < ll(B.size()); i++) {
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                }

                ++m;
            }
        }

        return C;
    }

private:
    ll mod{(ll)1e9 + 7};

    ll res[N], base[N], _c[N], _md[N];
    std::vector<ll> Md;

private:
    Options options_;
};

}  // namespace algorithmic::math

#endif  // ALGORITHMIC_MATH_BM_BM_PRIME_H_
