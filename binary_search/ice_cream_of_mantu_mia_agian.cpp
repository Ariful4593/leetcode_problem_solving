#include<iostream>
#include<vector>

using namespace std;


int canIceCreamBuy(vector <int>& priceArr, vector <int>& iceCreamArr)
{
    int counter = 0;
    for(int i = 0; i < priceArr.size() && iceCreamArr.size(); i++){
        for(int j = 1; j < priceArr.size() && iceCreamArr.size(); j++){
            if(priceArr[i] == iceCreamArr[j]){
                counter++;
            }
        }
    }



    /*int mid, left = 0, right = iceCreamArr.size() - 1;


    while(left <= right){
        mid = left + (right - left) / 2;

        if(iceCreamArr[mid] == priceArr){
            counter++;
            return counter;
        }

        if(iceCreamArr[mid] < priceArr){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }*/



    return counter;
}
int main()
{
    vector <int> mantuEachNote;
    vector <int> priceOfEachIcecream;
    vector <int> flag;

    int note,icecream;
    cin >> note;

    for(int i = 0; i < note; i++){
        int a;
        cin >> a;
        mantuEachNote.push_back(a);
    }
    cout << endl;
    cin >> icecream;

    for(int i = 0; i < icecream; i++){
        int ice;
        cin >> ice;
        priceOfEachIcecream.push_back(ice);
    }

    //It's normal usecase
    cout << canIceCreamBuy(mantuEachNote, priceOfEachIcecream);



    /*It's for binary search
    int sum = 0;
    for(int i = 0; i< note && icecream; i++){
       sum = canIceCreamBuy(mantuEachNote[i], priceOfEachIcecream);
    }

    cout << sum;*/

}
