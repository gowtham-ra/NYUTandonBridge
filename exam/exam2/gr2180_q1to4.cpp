//Gowtham Rajeshshekaran
//gr2180


/*
 Q1) Proof:
        Proof by strong induction on n.

    Base Case:
        n = 1, a1 = 1, 2^1-1 = 1 >= 1
        n = 2, a2 = 1, 2^2-1 = 2 >= 1

        when n = 3
        a3 = 2
        2^3-1 = 4
        Therefore, a1,a2, a3 are true

    Inductive Step:
        For any k >= 3, for any i in the range 1 to k aj <= 2^j-1 and show that ak+1 <= 2^k
        ak and ak-1 are part of the inductive hypothesis


        ak+1 = ak + ak-1
             <= 2^k-1 + 2^k-2 (Inductive hypothesis)
             <=  2^k-1 + 2^k-1  (k >= 3)
             <= 2^k


 Q2)    When 3 1s and 2s are same --> 2^6 (all should be 1 or 2)
        When 2 1s and 2s are same --> 2^4 * C(6,2) (2 0s are there)
        When 1 1s and 2s are same --> 2^2 * C(6,4) (4 0s are there)
        When 0 1s and 2s are same --> 2^6 * C(6,6) (6 0s are there)
        Ans = 2^6 + 2^4 * C(6,2) + 2^2 * C(6,4) + 2^6 * C(6,6)

 Q3)    X is the Random Variable denotes the winning of player in one game
        X = 10 (When the sum of two numbers = 7 or 11)
        X = 20 (When the sum of two numbers = 12)
        X = -1 (When the sum of two numbers is anything other than 7, 11 or 12)

      a. Distribution of X
        P(X = 10) = 8 / 36
        P(X = 20) = 1 / 36
        P(X = -1) = 27 / 36


       b. E[X]  = 10 * P(X = 10) + 20 * P(X = 20) - 1 * P(X = -1)
                = 10 * (8/36) + 20 * (1 / 36) -1 (27 / 36)
                = (80 + 20 - 27) / 36
                = 73 / 36
                = 2.028


 Q4) Func1:
        First for loop runs 'n' times to assign values for the arr.

        In second loop,
            the outer loop runs 'n' times because the loop runs once for each element in the arr and there are
            n no of elements.

            the inner loop each iteration is based on the the value of arr[i].
            the values of arr = 1, 3, 5, 7, 9, .... (2n - 1)
            therefore, the inner loop runs (2n - 1) times for each iteration of outer loop

        So,
            the total number of times first loop runs = n
            the total number of times the nested loops run = n * (2n - 1) = 2n^2 - n
            taking all other constant operations as c
            Total run time = n + 2n^2 - n + c
            Removing lower order terms, constants and coefficients,
            T(n) = theta(n^2)

     Func2:
        First for loop runs 'n' times to assign values for the arr.

        In the second loop,
            the outer loop runs 'n' times because the loop runs once for each element in the arr and there are
            n no of elements.

            the inner loop each iteration is based on the the value of arr[i].
            the values of arr = 2, 4, 8, 16,.... (2^n)
            therefore, the inner loop runs (2^n) times for each iteration of outer loop

         So,
            the total number of times first loop runs = n
            the total number of times the nested loops run = n * (2^n) = 2^(n+1)
            taking all other constant operations as c
            Total run time = n + 2^(n+1) + c
            Removing lower order terms, constants and coefficients,
            T(n) = theta(2^n)
 */