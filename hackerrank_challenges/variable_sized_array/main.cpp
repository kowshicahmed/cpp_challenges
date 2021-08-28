#include <vector>
#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    size_t row{}, col{}, ques_no{};
    int k{0};
    
    vector <int> size_data;
    
    int vector_data{};
    
    cout << "Enter row: ";
    
    cin >> row;
    
    cout << "Enter No of qustion: ";
 
    cin >> ques_no;
    
    vector<vector<int>> data_vector(row);
    
    cout << "Rows in the data vector: " << data_vector.size() << endl;
    
    for (size_t i{0}; i<row; i++)
    {
        cout << "Enter no of collumn for row " << i <<":";
        cin >> col;
        data_vector [i]= vector <int> (col+1);
        cout << "Collumns in the data vector: " << data_vector[i].size() << endl;
        //data_vector[i].push_back(k);
        data_vector[i][0] = k;
        for (size_t j{0}; j < col; j++)
        {
            cout << "Enter data for row " << i << " collumn " << j+1 << ":";
            cin >> vector_data;
            data_vector[i][j+1] = vector_data;
            //data_vector[i].push_back(vector_data);
        }
        k++;
        
    }
    
    //cout << data_vector.at(0).at(2) << endl;
    
    
    size_t array_index {};
    size_t data_index {};
    
    for (size_t i{0}; i < ques_no; i++)
    {
        cout << "Enter array index ";
        cin >> array_index;
        cout << "Enter data index ";
        cin >> data_index;
        cout << data_vector.at(array_index).at(data_index+1) << endl;
    }
    
    return 0;
}
