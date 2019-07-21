#include <iostream>
#include <vector>
//User fill vector and try to get value by index and find his own value in this vector
using namespace std;

void Fill_user_vector(vector<float>& user_vec)
{
    char finish_fill = 'n';
    while (finish_fill != 'y')
    {
        cout << "Enter your number:";
        float user_num = 0;
        cin >> user_num;
        user_vec.push_back(user_num);
        cout << "Want to finish fill? Press 'y' if yes or 'n' to continue:";
        cin >> finish_fill;
    }
    cout << "Size of your vector is: " << user_vec.size() << endl;
}

void User_Index(vector<float>& user_vec)
{
    char finish_search = 'y';
    while(finish_search != 'n'){
        cout << "Enter your index:";
        int index = 0;
        cin >> index;
            if(index > user_vec.size() - 1 || index < 0)
            {
                cout << "There is no element with this index" << endl;
                cout << "Please try another number or finish search by pressing 'n':";
                cin >> finish_search;
            }else
            {
                cout << "Your value with index [" << index << "] is:" << user_vec[index] << endl;
                cout << "Want to find other value? Press 'n' if not ot 'y' to begin other search:";
                cin >> finish_search;
            }
    }
}

void User_Value(vector<float>& user_vec)
{
    char finish_value_search = 'y';
    while(finish_value_search != 'n')
    {
        cout << "Enter your value:";
        float user_val = 0;
        cin >> user_val;
        int position = user_vec.size();
        int index = 0;
        int count_found = 0;
        while (position > 0)
        {
            if(user_val == user_vec[index])
            {
                cout << "User value " << user_val << " found in position: [" << index << "]" << endl;
                count_found--;
            }
            index++;
            position--;
        }
        if(count_found == 0)
            cout << "There is no your value " << user_val << " in this vector" << endl;
        cout << "Want to repeat? Press 'n' if not or 'y' to find other value:";
        cin >> finish_value_search;
    }
}

int main() {

    vector<float> user_vector;
    char finish = 'y';
    while (finish != 'n')
    {
        cout << "Fill your vector:" << endl;
        Fill_user_vector(user_vector);
        cout << "Get access to element of the vector by index? Press 'y' if you want and 'n' if not:";
        char access = 'n';
        cin >> access;
        if(access == 'y')
        {
            User_Index(user_vector);
        }
        cout << "Try to find your value? Press 'y' to begin or 'n' to skip:";
        char find_val = 'n';
        cin >> find_val;
        if(find_val == 'y')
        {
            User_Value(user_vector);
        }
        cout << "Do you want to try again program? Press 'n' to finish or 'y' to repeat:";
        cin >> finish;
    }
    cout << "End of the program. Goodbye!" << endl;
    return 0;
}
