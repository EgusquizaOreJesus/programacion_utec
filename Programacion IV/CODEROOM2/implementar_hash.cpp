#include <iostream>
#include "chainhash.h"
#include "unordered_map"
using namespace std;

int main()
{
    ChainHash<string, int> myhash;

    myhash.insert(make_pair<string,int>("luis", 20));
    myhash.insert(make_pair<string,int>("sara", 21));
    myhash.insert(make_pair<string,int>("jorge", 19));
    myhash.insert(make_pair<string,int>("antonia", 16));
    myhash.insert(make_pair<string,int>("josimar", 19));
    myhash.insert(make_pair<string,int>("ximena", 19));
    myhash.insert(make_pair<string,int>("criscrack", 20));
    myhash.insert(make_pair<string,int>("alejandro", 19));
    myhash.insert(make_pair<string,int>("Wakaru", 13));
    myhash.insert(make_pair<string,int>("ximena", 19));
    myhash.insert(make_pair<string,int>("Bocchi", 15));
    myhash.insert(make_pair<string,int>("Diego",15));
    myhash.insert(make_pair<string,int>("jose", 19));
    myhash.insert(make_pair<string,int>("Milloshy", 18));
    myhash.insert(make_pair<string,int>("Luisa", 19));
//    myhash.insert(make_pair<string,int>("Luisa", 22));
    myhash.insert(make_pair<string,int>("jose", 20));
    myhash.insert(make_pair<string,int>("josefina", 21));
    myhash.insert(make_pair<string,int>("1212244", 21));
    myhash["pedro"] = 19;
    myhash.insert(make_pair<string,int>("josefina", 39));


    myhash.insert(make_pair<string,int>("Cristina", 21));
    myhash.insert(make_pair<string,int>("Cristiano", 21));
    myhash.insert(make_pair<string,int>("Pedrito", 21));
    myhash.insert(make_pair<string,int>("Bruno", 21));
    myhash.insert(make_pair<string,int>("Brunela", 21));
    myhash.insert(make_pair<string,int>("Solis", 21));
    myhash.insert(make_pair<string,int>("Gaaaa", 21));
    myhash.insert(make_pair<string,int>("Miguelon", 21));
    myhash.display();

    myhash.insert(make_pair<string,int>("Enrique", 21));


    myhash.display();

//    ForwardList<int> temp = myhash.merge();
//    temp.display();

    myhash.remove("Enrique");
    myhash.display();
//    ForwardList<string> temp2;
//    temp2.push_front("hola");
//    temp2.push_front("alex");
//    temp2.push_front("fabricio");
//    temp2.sort();
//    temp2.display();

}
