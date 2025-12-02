// File created by: Liam Newberry & Lyle Stone

#ifndef DNA_H
#define DNA_H

#include <string>

using namespace std;

class DNA {
public:
    static double strandSimilarity(string strand1, string strand2);
    static string transcribeDNAtoRNA(string strand);
    static void identifyMutations(string input_strand, string target_strand);
    static string makeInputStrand();
    static string makeTargetStrand(string input_strand, bool shorter);
    static void printNeucleotide(char c);
    static void printStrand(string strand);

private:
    static int bestStrandMatch(string input_strand, string target_strand);
    static void fillInTargetStrand(string input_strand, string& target_strand);
};

#endif