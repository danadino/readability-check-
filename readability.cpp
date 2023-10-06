#include<iostream>
#include<string>
#include<cmath>
// for round function

using namespace std;

// letter calculation
int letter(string txt) {
    int letters = 0;
    for (int i = 0; i < txt.length(); i++)
    {
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

// words calculation
int word(string txt) {

    int words = 1;
    for (int i = 0; i < txt.length(); i++)
    {
        if (txt[i] == '\t' || txt[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// sentences calculation  
int sent(string txt) {
    int sents = 0;
    for (int i = 0; i < txt.length(); i++)
    {
        if (txt[i] == '!' || txt[i] == '?' || txt[i] == '.')
        {
            sents++;
        }
    }
    return sents;
}


int main() {
    string txt;
    cout << "text: ";
    getline(cin, txt);

    int L = letter(txt);
    int W = word(txt);
    int S = sent(txt);
    cout << "letters: " << L << "\n";
    cout << "words: " << W << "\n";
    cout << "sentences:" << S << "\n";

    //calculating index value according to coleman-liau index law
    float index = (0.0588 * L / W * 100) - (0.296 * S / W * 100) - 15.8;


    int grade = round(index);

    //precautions so there is no negative or above limit values
    if (index < 1)
    {
        cout << "before grade 1";
        return 0;
    }
    else if (index > 16)
    {
        cout << "above grade 16";
        return 0;
    }
    else
    {

        cout << "grade: " << grade;
    }


}