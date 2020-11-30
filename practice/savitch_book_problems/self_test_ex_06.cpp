// Created by Gowtham Ra on 20/09/20.
// Self Test Exercises - Chapter 06
// [Y] - RIGHT ANSWER; [N] - WRONG ANSWER
// SCORE = 31 / 35 89%

/*
 1. #include<fstream>
    ifstream fin;
    ofstream fout; ---- [Y]

 2. fin.open("stuff1.dat");
    if (fin.fail()) {
        cout << "Input file opening failed\n";
        exit(1);
    }

    fout.open("stuff2.dat");
    if (fout.fail()) {
        cout << "Output file opening failed\n";
        exit(1);
    } ---- [Y]

 3. fin.close();
    fout.close(); ---- [Y]

 4. cout << "The sum of the first 3\n"
         << "numbers in infile.dat\n"
         << "is " << (first + second +third)
         << endl; ---- [Y]

 5. #include <cstdlib> ---- [Y]

 6. It exits the program with the error code 1. ---- [Y]

 7. bla.dobedo(7); ---- [Y]

 8. What characteristics of files do ordinary program variables share? What
    characteristics of files are different from ordinary variables in a program?

    Both files and program variables store values and can have values retrieved
    from them. Program variables exist only while the program runs, whereas
    files may exist before a program is run and may continue to exist after a
    program stops. In short, files may be permanent; variables are not. Files
    provide the ability to store large quantities of data, whereas program variables
    do not provide quite so large a store. ---- [N]

 9. fin.open()
    fin.close()
    fin.fail() ---- [Y]

 10. Close the previous connection and reconnect the file again to the stream. ---- [Y]

 11. External file name --> Used while opening the file.
     Stream name --> used for accessing the file inside the program everytime. ---- [Y]

 12. *  123*123*
     *  123*123* (Both same output) ---- [Y]

 13. *  123*123  *  123* ---- [Y]

 14. *  123*123* ---- [Y]
     * +123*+123* ---- [Y]
     *+123 * +123* ---- [N]

 15. *  123*123* ---- [Y]
     * +123*+123* ---- [Y]
     *123  *  123* ---- [N]

 16. *12345* ---- [Y]

 17. a) Floating point numbers are showed in fixed point notation. ---- [Y]
     b) Floating point numbers are showed in e-notation. ---- [Y]
     c) Shows the decimal point after a number even if it has only 0s in the significant digits. ---- [Y]
     d) Shows a positive sign in front of the positive numbers. ---- [Y]
     e) Shows the output right side when combined with width. ---- [Y]
     f) Shows the output left side when combined with width. ---- [Y]

 18. Replace outstream with cout. ---- [Y]

 19. 1
     2
     3
     3 ---- [Y]

 20. void to_screen(ifstream& file_stream) {
         double next;
         while (file_stream >> next) {
            cout << next << endl;
         }
     } ---- [Y]

 21. A name with 20 characters. ---- [Y]

 22. a. Gets one character as input even if it is a blank space or \n.
     b. Gets one character as input and ignores the blank spaces and \n. ---- [Y]

 23. There are no differences, both does the same thing. ---- [Y]

 24. It can only put back the last symbol read in this case only 'a'. ---- [N]

 25. a b END OF OUTPUT ---- [Y]

 26. ace h ---- [Y]

 27. 01234567891 1 ---- [Y]

 28. 0246811 ---- [Y]

 29. void copy_char (istream& ins) {
         char c;
         ins.get(c);
         cout.put(c);
     } ---- [Y]

 30. void copy_line(istream& ins) {
         string input;
         getline(ins, input);
         cout << input;
     } ---- [Y]

 31. void send_line(ostream& outs) {
         string input;
         getline(cin, input);
         outs << input;
     } ---- [Y]

 32. a. 2.0 1.1 2.3
     b. 2.0 3.0 2.3
     c. 2.0 3.0 4.0 ---- [Y]

 33. CHILL BRO

 34. False ---- [Y]

 35. void text_to_screen (ifstream& file_stream) {
        char c;
        file_stream.get(c);
        while (!file_stream.eof()) {
            cout.put(c);
            file_stream.get(c);
        }
     } ---- [Y]

 36. I’ll see you at 1<END OF OUTPUT ---- [Y]

 37. program. chill bro.


 */