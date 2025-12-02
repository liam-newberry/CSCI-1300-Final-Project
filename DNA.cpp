// File created by: Liam Newberry & Lyle Stone

#include "DNA.h"
#include "HelperMethods.h"
#include "EscapeColors.h"

#include <iostream>

using namespace std;

double DNA::strandSimilarity(string strand1, string strand2) {
    if (strand1.size() != strand2.size()) {
        string smaller = strand1.size() < strand2.size() ? strand1 : strand2;
        string bigger = strand1.size() > strand2.size() ? strand1 : strand2;
        strand1 = bigger;
        strand2 = smaller;

        strand1 = strand1.substr(bestStrandMatch(bigger, smaller), smaller.size());
    }

    int count = 0;
    for (int i = 0; i < strand1.size(); i++) {
        if (strand1[i] == strand2[i]) {
            count++;
        }
    }

    return (count * 1.0) / strand1.size();
}

string DNA::transcribeDNAtoRNA(string strand) {
    for (int i = 0; i < strand.size(); i++) {
        if (strand[i] == 'T') {
            strand[i] = 'U';
        }
    }

    return strand;
}

void DNA::identifyMutations(string input_strand, string target_strand) {
    fillInTargetStrand(input_strand, target_strand);
    cout << input_strand << endl << target_strand << endl << endl;
    
    for (int i = 0; i < input_strand.size(); i++) {
        if (target_strand[i] == '_') { // deletion
            cout << EscapeColors::colorString("Deletion    ", EscapeColors::RED)
                 << " at position " << i + 1 << ": " << (i <= 9 ? " " : "");
            printNeucleotide(input_strand[i]);
            cout << " is deleted in the target strand" << endl;

        } else if (input_strand[i] != target_strand[i]) {
            if ((i >= 1 && target_strand[i - 1] == '_') ||
                (i <= target_strand.size() - 2 && target_strand[i + 1] == '_')) { // insertion
                    cout << EscapeColors::colorString("Insertion   ", EscapeColors::BLUE)
                         << " at position " << i + 1 << ": " << (i <= 9 ? " " : "");
                    printNeucleotide(target_strand[i]);
                    cout << " is added to the target strand" << endl;

            } else { // substitution
                cout << EscapeColors::colorString("Substitution", EscapeColors::YELLOW)
                     << " at position " << i + 1 << ": " << (i <= 9 ? " " : "");
                printNeucleotide(input_strand[i]); 
                cout << " -> ";
                printNeucleotide(target_strand[i]); 
                cout << endl;
            }
        }
    }

    cout << endl;
}

string DNA::makeInputStrand() {
    int strand_length = HelperMethods::randomInt(8,12);

    string strand = "";

    for (int i = 0; i < strand_length; i++) {
        switch (HelperMethods::randomInt(1,4)) {
            case 1: strand += "A"; break;
            case 2: strand += "C"; break;
            case 3: strand += "G"; break;
            case 4: strand += "T"; break;
        }
    }

    return strand;
}

string DNA::makeTargetStrand(string input_strand, bool shorter) {
    for (int i = 0; i < input_strand.size(); i++) {
        if (HelperMethods::randomInt(1,3) == 1) {
            switch (HelperMethods::randomInt(1,4)) {
                case 1: input_strand[i] = 'A'; break;
                case 2: input_strand[i] = 'C'; break;
                case 3: input_strand[i] = 'G'; break;
                case 4: input_strand[i] = 'T'; break;
            }
        }
    }

    if (shorter) {
        int left_missing =  HelperMethods::randomInt(3);
        int right_missing = HelperMethods::randomInt(3);
        input_strand = input_strand.substr(left_missing,
                                           input_strand.size() - (left_missing + right_missing));
    }

    return input_strand;
}

// print a certain color for each nucleotide
void DNA::printNeucleotide(char c) {
    switch (c) {
        case 'A': cout << EscapeColors::colorString("A", EscapeColors::GREEN);  break;
        case 'C': cout << EscapeColors::colorString("C", EscapeColors::BLUE);   break;
        case 'G': cout << EscapeColors::colorString("G", EscapeColors::YELLOW); break;
        case 'T': cout << EscapeColors::colorString("T", EscapeColors::RED);    break;
        case 'U': cout << EscapeColors::colorString("U", EscapeColors::CYAN);   break;
    }
}

void DNA::printStrand(string strand) {
    for (int i = 0; i < strand.size(); i++) {
        printNeucleotide(strand[i]);
        cout << " ";
    }
}

int DNA::bestStrandMatch(string input_strand, string target_strand) {
    double best = strandSimilarity(input_strand.substr(0, target_strand.size()), target_strand);;
    int best_index = 0;

    double similarity;
    for (int i = 1; i <= input_strand.size() - target_strand.size(); i++) {
        similarity = strandSimilarity(input_strand.substr(i, target_strand.size()), target_strand);
        if (similarity > best) {
            best = similarity;
            best_index = i;
        }
    }

    return best_index;
}

void DNA::fillInTargetStrand(string input_strand, string& target_strand) {
    int displacement = bestStrandMatch(input_strand, target_strand);

    for (int i = 0; i < displacement; i++) {
        target_strand = "_" + target_strand;
    }

    for (int i = target_strand.size(); i < input_strand.size(); i++) {
        target_strand += "_";
    }
}