#include <iostream>
#include <vector>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
    struct gene
    {
        int value;
        int weight;
    };
    cout << "Enter knapsack capacity!" <<endl;
    int knapsackSize;
    cin >> knapsackSize;
    int items;
    cout <<"Enter number of items to put in the knapsack!" << endl;
    cin >> items;
     gene arr[items];
    for(int i=0;i<items;i++)
    {
        cout << "Enter the weight of gene[" << i+1 << "]!" << endl;
        cin >> arr[i].weight;
        cout << "Enter the value of gene[" << i+1 << "]!" << endl;
        cin >> arr[i].value;
    }
    cout << "Enter population size of the problem!" << endl;
    int population;
    cin>> population;
    vector<vector<int>> chromosomes(population, vector<int>(items, 0));
    for(int i=0; i<population; i++)
    {
        for(int j=0;j<items;j++)
        {
            int binaryValue = rand() %2;
            chromosomes[i][j] = binaryValue;
        }
    }
    map<int,int> chromosomesValues;
    int index1stMaximum, index2ndMaximum;
    for (int i = 0; i < population; i++) {
        int fitnessValue = 0;
        int weightValue = 0;
        cout << "Chromosome " << i + 1 << ": ";
        for (int j = 0; j < items; j++) {
            cout << chromosomes[i][j] << ' ';
            if (chromosomes[i][j] == 1) {
                fitnessValue += arr[j].value;
                weightValue += arr[j].weight;
            }
        }
        if (weightValue <= knapsackSize)
        {
            cout << ", Fitness Value: " << fitnessValue << ", Weight: " << weightValue << "." << endl;
        }
        else
        {
            fitnessValue=0;
            cout << ", Fitness Value: " << fitnessValue << ", Weight: " << weightValue << ", exceeded knapsack capacity!" << endl;
        }
        chromosomesValues[i] = fitnessValue;
    }
    int maxFitnessValue = 0, secondMaxFitnessValue = 0;
    for(int i=0;i<population; i++)
    {
        if(chromosomesValues[i]>maxFitnessValue)
        {
            maxFitnessValue=chromosomesValues[i];
            index1stMaximum=i;
        }
    }
    chromosomesValues.erase(index1stMaximum);
    for(int i=0;i<population; i++)
    {
        if(chromosomesValues[i]>secondMaxFitnessValue)
        {
            secondMaxFitnessValue=chromosomesValues[i];
            index2ndMaximum=i;
        }
    }
    cout <<"Chromosome "<< index1stMaximum+1 << " is the fittest chromosome."<<endl;
    cout <<"Chromosome "<< index2ndMaximum+1 << " is the 2nd fittest chromosome."<<endl;
    //cout << "Cumulative Fitness Value: " << cumilativeFitnessValue <<endl;
    int randomNumber = rand() % items;
    cout << "Last " << randomNumber << " to be changed!" <<endl;
    for(int i=items-1; i>=(items-randomNumber);i--)
    {
         swap(chromosomes[index1stMaximum][i],chromosomes[index2ndMaximum][i]);
    }

    int newFitnessValue1st=0, newWeightValue1st=0;
    int newFitnessValue2nd=0, newWeightValue2nd=0;
    cout << "Chromosome " << index1stMaximum+1 << ": ";
    for(int i=0; i<items; i++)
    {
        cout << chromosomes[index1stMaximum][i] << " ";
        if(chromosomes[index1stMaximum][i])
        {
            newFitnessValue1st+=arr[i].value;
            newWeightValue1st+=arr[i].weight;
        }
    }
    cout << ", New Fitness Value: " << newFitnessValue1st << ", New Weight Value: " << newWeightValue1st << endl;
    cout << "Chromosome " << index2ndMaximum + 1 << ": ";
    for(int i=0; i<items; i++) {
        cout << chromosomes[index2ndMaximum][i] << " ";
        if(chromosomes[index2ndMaximum][i])
        {
            newFitnessValue2nd+=arr[i].value;
            newWeightValue2nd+=arr[i].weight;
        }
    }
    cout << ", New Fitness Value: " << newFitnessValue2nd << ", New Weight Value: " << newWeightValue2nd << endl;
    return 0;
}
