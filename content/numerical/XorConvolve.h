/**
 * Author: abhayps
 * Description: It transform P for xor conv.
 * Assumes P has $2^n$ coeff.
*/
vll FWHT(vll P, bool inverse) {
    for (len = 1; 2 * len <= degree(P); len <<= 1) {
        for (i = 0; i < degree(P); i += 2 * len) {
            for (j = 0; j < len; j++) {
                u = P[i + j];
                v = P[i + len + j];
                P[i + j] = u + v;
                P[i + len + j] = u - v;
            }
        }
    }
    if (inverse) {
        for (i = 0; i < degree(P); i++)
            P[i] = P[i] / degree(P);
    }
    return P;
}
