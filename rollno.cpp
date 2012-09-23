#include "rollno.h"

int RollNo :: A;
int RollNo :: B;
int RollNo :: Z;

RollNo :: RollNo()
{
    n = 0;
    row = col = 0;
    X = Y = 0;// Z = A = B = 0;
}

void RollNo :: get_details()
{
    infile.open("roll.in");
    infile>>total_branches;
    for(i = 0; i < total_branches; i++)
    {
        infile>>total_rno[i];
        for(j = 0; j < total_rno[i]; j++)
        {
            infile>>rollno[i][j];
        }
    }
    infile.close();
    infile.open("rooms.in");
    infile>>total_rooms;
    for( i = 0; i < total_rooms; i++)
    {
        infile>>room_no[i]>>rows[i]>>cols[i];
    }
    infile.close();
}

void RollNo :: arrange_rollno()
{
    if(n == 0)
    {
    	A=-1;
    	B=-1;
    	outfile.open("demo.txt");
        for(i = 0; i < 2; i++)
        {
            for(j = 0; j < total_rno[n]; j++)
            {
                set_rollno[i][j] = rollno[n][j];
                
                     outfile<<"\n" <<set_rollno[i][j];
            }
            set_trno[i] = total_rno[n];
            n++;
        }

    }
    else if(n < total_branches)
    {
        for(j = 0; j < total_rno[n]; j++)
        {
            set_rollno[Z][j] = rollno[n][j];
        }
        set_trno[Z] = total_rno[n];
        n++;
    }
    else
    {
        if( Z == 0 )
        {
            A = 0;
            set_trno[Z] = 0;
            set_rollno[Z][A] = 0;
        }
    
        if( Z == 1 )
        {
            B = 0;
            set_trno[Z] = 0;
            set_rollno[Z][B] = 0;
        }
    }
}

void RollNo :: next_rollno()
{
    if( Z == 0 )
    {
        if(A >= set_trno[Z]-1)
        {
            arrange_rollno();
            A = 0;
        }
        else
            A++;
    }
    
    if( Z == 1 )
    {
        if(B >= set_trno[Z]-1)
        {
            arrange_rollno();
            B = 0;
        }
        else
            B++;
    }
    
}

void RollNo :: seat_alot()
{
    arrange_rollno();
    for(z = 0; z < total_rooms; z++)
    {
        row = rows[z];
        col = cols[z];
        
        for(x = 0; x < row; x++)
        {
            for(y = 0; y < col; y++)
            {
                switch(Z)
                {
                    case 0:
                        next_rollno();
                        seat[z][y][x] = set_rollno[Z][A];
                        outfile << "\n\n" << seat[0][0][0] <<"\t" <<set_rollno[Z][A] <<"\t "<< Z  <<" "<<A;
//                        A++;
                        Z++;
                        break;
                    
                    case 1:
                        next_rollno();
                        seat[z][y][x] = set_rollno[Z][B];
//                        B++;
//                        next_rollno();
                        Z++;
                        break;
                }
                if(Z > 1)
                    Z = 0;
            }
        }
    }
}

void RollNo :: show_details()
{
    cout<<"ROLL NO. DETAILS"<<endl
        <<total_branches<<endl;
    for(i = 0; i < total_branches; i++)
    {
        cout<<total_rno[i]<<'\t';
        for(j = 0; j < total_rno[i]; j++)
        {
            cout<<rollno[i][j]<<'\t';
        }
        cout<<'\n';
    }
    
    cout<<"ROLL NO. DETAILS"<<endl
        <<total_rooms<<endl;
    for( i = 0; i < total_rooms; i++)
    {
        cout<<room_no[i]<<'\t'<<rows[i]<<'\t'<<cols[i]<<endl;
    }
    
    cout<<"\n SEAT ALOTTing \n \n";
    for(i = 0; i < total_rooms; i++)
    {
        cout<<"\n\n=============== Room No: "<<room_no[i]<<"===============\n\n";
        for(x = 0; x < rows[i]; x++)
        {
            for(y = 0; y < cols[i]; y++)
            {
                cout<<seat[i][x][y]<<"\t";
            }
            cout<<"\n";
        }
    }
}
