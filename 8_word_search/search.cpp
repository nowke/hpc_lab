#include <iostream>
#include <fstream>
#include <omp.h>
#include <string>

using namespace std;

string words[10] = {"the", "around", "graphics", "from", "by", "be", "any", "mount", "hello", "word"};
int count[10];

int word_count(string file_name, string word) {
    int count = 0;
    string ch;
    ifstream input_file(file_name);

    while (input_file) {
        input_file >> ch;
        if (ch == word)
            count++;
    }
    input_file.close();
    return count;
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        cout << "Usage: ./search words1.txt num_threads" << endl;
        return 1;
    }

    string file_name = argv[1];
    int num_threads = atoi(argv[2]);

    double t1 = omp_get_wtime();

    #pragma omp parallel for num_threads(num_threads)
    for (int i=0; i<10; i++)
        count[i] = word_count(file_name, words[i]);

    double t2 = omp_get_wtime();

    for (int i=0; i<10; i++)
        cout << words[i] << ": " << count[i] << endl;
    cout << endl;

    cout << "Time: " << (t2-t1) * 1000 << "ms" << endl;

    return 0;
}
