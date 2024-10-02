#include <iostream>
using namespace std;

struct card
{
    string alphabet;
    int number;
    int default_index;
};

void quicksort(card list[], int left, int right);
int partition(card list[], int left, int right);
bool isStable(card list[], int size);

int main()
{
    int card_size;
    cin >> card_size;
    card list[card_size];
    for (int i = 0; i < card_size; i++)
    {
        cin >> list[i].alphabet >> list[i].number;
        list[i].default_index = i;
    }
    
    quicksort(list, 0, card_size - 1);

    if (isStable(list, card_size))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    for (int i = 0; i < card_size; i++)
    {
        cout << list[i].alphabet << " " << list[i].number << endl;
    }
}

void quicksort(card list[], int left, int right)
{
    if (!(left < right))
        return;

    int division_position = partition(list, left, right);
    quicksort(list, left, division_position - 1);
    quicksort(list, division_position + 1, right);
}

int partition(card list[], int left, int right)
{
    int last = list[right].number;
    int small_than_right = left - 1;
    for (int i = left; i < right; i++)
    {
        if (list[i].number <= last)
        {
            small_than_right++;
            swap(list[small_than_right], list[i]);
        }
    }
    swap(list[small_than_right + 1], list[right]);
    return small_than_right + 1;
}

bool isStable(card list[], int size)
{
    bool stable_flag = true;

    for (int i = 1; i < size; i++)
    {
        while (list[i - 1].number == list[i].number)
        {
            if (list[i - 1].default_index > list[i].default_index)
            {
                stable_flag = false;
                return stable_flag;
            }
            i++;
        }
    }

    return stable_flag;
}