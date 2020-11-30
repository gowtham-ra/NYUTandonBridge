//Name: Gowtham Rajeshshekaran
//Date: 03/09/20
//NetID: gr2180

/*
Q1. Yes Proof:
    Proof by induction on n.
    Base case:
        when n = 4,
        left side of equation = 4! = 24
        right side of equation = 2^4 = 16
        Therefore, n! > 2^n for the base case n = 4.

    Inductive Step:
        For any positive integer k >= 4, Lets assume that k! > 2^k and we show that (k+1)! > 2^(k+1)

        (k+1)!  = (k+1) * k!
                > (k+1) * 2^k
                > 2^k * k + 2^k
                > 2^k + 2^k               (since k >= 4, k >= 1)
                = 2*2^k = 2^(k+1)

        Therefore (k+1)! > 2^(k+1)
        Therefore n! > 2^n for any n >= 4

        RV : k+1 > 2 since k >= 4

Q2. c) 1/3  Yes  RV: neither A or B = (A U B)c

Q3. (c) C(6, 4) * C(7, 4) * 4! - No RV: Ans 4! ---- CHECK AGAIN

Q4. P(A) = 0.4 P(B) = 0.3 P((A ∪ B)^c) = 0.42
    P(AUB)  = 1 - P((A ∪ B)^c)
            = 1 - 0.42
            = 0.58                      --- (1)

    P(A) * P(B) = 0.12                  --- (2)

    If A and B are independent,
    P(A ^ B) = P(A) * P(B)              --- (3)

    As per Union law,
    P(AUB) = P(A) + P(B) - P(A ^ B)     --- (4)

    Sub 3 in 4,
    P(AUB)  = P(A) + P(B) - P(A) * P(B)
    P(AUB)  = 0.4 + 0.3 - 0.12           (sub 2)
            = 0.58
            = (1)

    Therefore, A and B are independent

Q5. (d) 35 -- YES

Q6. 11! / (2! * 2!) -- YES
    =  99,79,200 (can we use mac search calculator)

Q7. (b) O(n ∗ m) -- YES

Q8. (a) O(n) -- YES

Q9. (b) 41 17 7 -- YES

Q10.
    n = 100 (no of people)
    Xi = i no of people who get their own hat.
    P(X = 1) = 1 / 100
    E[X1] = 1 * 1 / 100 = 1 / 100

    Since it is a uniform distribution (all outcomes are equally likely), expected number is same for all Xi
    E[X]    = n * E[X1]
            = 100 * 1 / 100
            = 1
    Therefore, the expected number of people who get their own hat back = 1
 */
