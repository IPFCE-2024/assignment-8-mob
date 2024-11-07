long fact(int n) {
    // precondition:
    assert(n >= 0);
    long f = 1;
    for (long i = 1; i <= n; i++) {
        f = i * f;
    }
    return f;
}
