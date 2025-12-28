/**
 * Author: Simon Lindholm
 * Date: 2016-07-24
 * License: CC0
 * Source: Russian page
 * Description:
 * Status: Works
 */
long long chinese_remainder_theorem(vector<pair<ll,ll> > const& congruences) { long long M = 1;
    for (auto const& congruence : congruences)
            M *= congruence.second;
    long long solution = 0;
    for (auto const& congruence : congruences) {
    long long a_i = congruence.first;
    long long M_i = M / congruence.second;
    long long N_i = mod_inv(M_i, congruence.second); solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}