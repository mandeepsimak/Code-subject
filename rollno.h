#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

const int MIN_SIZE = 50;
const int MAX_SIZE = 100;

class RollNo
{
    int rollno[MIN_SIZE][MAX_SIZE], total_rno[MIN_SIZE], total_branches, 
        set_rollno[MIN_SIZE][MAX_SIZE], n, set_trno[MIN_SIZE],
        i, j, k, total_rooms, rows[MIN_SIZE], cols[MIN_SIZE], row, col,
        seat[MIN_SIZE][MIN_SIZE][MAX_SIZE], x, y, z, X, Y, C, D;//, Z, A, B;
    
    string branch_name[MIN_SIZE], room_no[MIN_SIZE];
    
    static int A, B, Z;
    
    ifstream infile;
    ofstream outfile;
    
    public:
    
    RollNo();
    void get_details();
    void show_details();
    void arrange_rollno();
    void seat_alot();
    void next_rollno();
};

