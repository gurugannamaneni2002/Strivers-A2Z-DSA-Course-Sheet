This is a solid implementation of **LeetCode 50 (Pow(x, n))** using fast exponentiation. Let me walk through why it works and flag a couple of things worth knowing.

## Why it's correct

**The `int` → `long long` cast matters.** If `n = INT_MIN` (-2147483648), then `-n` would overflow a 32-bit `int` (since the positive range only goes up to 2147483647). By storing `n` in a `long long` first and negating *that*, you avoid undefined behavior. This is the classic edge case this problem is designed to test.

**The recursion itself (fast/binary exponentiation):**
- `pow(x, n/2)` is computed once and squared, giving `x^n` in `O(log n)` multiplications instead of `O(n)`.
- Odd `n` gets one extra factor of `x` to correct for integer division truncation (e.g., `n=5` → `n/2=2`, so `x^5 = (x^2)^2 * x`).

## Trace check
- `myPow(2.0, -2)` → `N = -2` → `1 / pow(2.0, 2)` → `pow` recurses: `pow(2,2)` → `ans = pow(2,1) = 2` → even, so `ans = 2*2 = 4` → `1/4 = 0.25` ✅

## Minor notes (not bugs, just style)

1. **Naming `pow`** shadows `std::pow` from `<cmath>`. It compiles fine here since it's a member function with a different signature, but if this were ever moved outside the class or `using namespace std;` were added elsewhere, it could cause ambiguity/confusion. Renaming to `fastPow` is a common convention.
2. **Recursion depth**: `O(log n)` stack frames — negligible for the constraint ranges LeetCode uses (`|n| ≤ 2^31 - 1`), but an iterative version avoids stack usage entirely if that ever mattered:
```cpp
double myPow(double x, int n) {
    long long N = n;
    if (N < 0) { x = 1 / x; N = -N; }
    double ans = 1;
    while (N > 0) {
        if (N % 2 == 1) ans *= x;
        x *= x;
        N /= 2;
    }
    return ans;
}
```

**Time complexity:** O(log n), **Space:** O(log n) for your recursive version (O(1) for the iterative one).

Overall — correct, handles the classic `INT_MIN` trap properly, and uses the right algorithmic approach. Nice work.
