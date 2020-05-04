// CSC A48 - Exercise 9 - Caesar Cipher v2.0
// Complete where indicated below.
//
// Do not add any additional functions
// and do not leave any print statements
// in your final submission for testing!
//
// F. Estrada, Updated March 2020.

#include<stdio.h>
#include<stdlib.h>

#define MAX_STR_LEN 2048

void caesar_cipher(unsigned char plaintext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN])
{
 // This function encodes the input text in plaintext[] using the caesar
 // cipher process with the specified password (please see the exercise
 // description to see how that works).
 //
 // The function must ensure that the 'end-of-string' delimiter is preserved,
 // and that no other character can become the 'end-of-string'.
 //
 // You want to make sure you understand what values can be stored in each
 // entry of the plaintext[] string, and you'll want to look at an ASCII table
 // to check that your function does the right thing.
 //
 // *** TEST your code with multiple input strings, using different passwords,
 //     and verify it works in
 //     every case! if you get incomplete because your function failed our
 //     tests it means you did not test carefully enough.
    //what if you add to delimiter or subtract to delimiter
    
    int j = 0;
    for (int i = 0; i < MAX_STR_LEN && plaintext[i] != '\0'; i++) {
        if (password[j] == '\0') j = 0;
        
        int n = (int) plaintext[i] + (int) password[j];
        if(n > 255) plaintext[i] = (char) n - 255; // same as n - 256 + 1;
        else plaintext[i] = (char) n;

        // plaintext[i] += password[j];

        // if (plaintext[i] == '\0')
        //     plaintext[i] += password[j];


        j++;
    }
}

void caesar_decipher(unsigned char cryptotext[MAX_STR_LEN], unsigned char password[MAX_STR_LEN])
{
 // This function reverses the encryption process and returns the original
 // text given the encrypted string and the password used to encrypt it.
 //
 // The function has the same constraints as 'caesar_cipher()', that is, it
 // must respect the 'end-of-string' delimiter, and ensure no other
 // character becomes 'end-of-string' after decoding.
 //
 // Be smart about how you implement this function!
    
 // TO DO: Implement this function
    int j = 0;
       for (int i = 0; i < MAX_STR_LEN && cryptotext[i] != '\0'; i++) {
           if (password[j] == '\0') j = 0;
           int n = (int) cryptotext[i] - (int) password[j];
           if(n < 0) cryptotext[i] = (char) n + 255;
           else cryptotext[i] = (char) n;

           // cryptotext[i] -= password[j];

           // if (cryptotext[i] == '\0')
           //     cryptotext[i] -= password[j];

           j++;
       }
}

#ifndef __testing

int main()
{
    
    char a_passage[5][MAX_STR_LEN]={"When did the world begin and how? \n   I asked a lamb, a goat, a cow:\n",
                                    "What’s it all about and why? \n    I asked a hog as he went by:\n",
                                    "Where will the whole thing end, and when? \n   I asked a duck, a goose and a hen:\n",
                                    "And I copied all the answers too, \n   A quack, a honk, an oink, a moo.\n",
                                    " --- Robert Clairmont\n"};
 
    printf("**** Original input text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Encode the input test lines
    caesar_cipher(&a_passage[0][0],"Blueberries are blue");
    caesar_cipher(&a_passage[1][0],"Blueberries are blue");
    caesar_cipher(&a_passage[2][0],"Blueberries are blue");
    caesar_cipher(&a_passage[3][0],"Blueberries are blue");
    caesar_cipher(&a_passage[4][0],"Blueberries are blue");

    printf("\n**** Encrypted text lines:\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);

    // Decode the encrypted strings
    caesar_decipher(&a_passage[0][0],"Blueberries are blue");
    caesar_decipher(&a_passage[1][0],"Blueberries are blue");
    caesar_decipher(&a_passage[2][0],"Blueberries are blue");
    caesar_decipher(&a_passage[3][0],"Blueberries are blue");
    caesar_decipher(&a_passage[4][0],"Blueberries are blue");

    printf("\n**** Decoded text lines (should be identical to original input!):\n\n");
    for (int i=0; i<5; i++)
        printf("%s",a_passage[i]);
    
    return 0;
    
}

#endif
