/*
Write a program that accepts n products' details and calculates and displays the total value of the 
inventory (i.e., quantity * price). Find the product with the highest quantity and the product with the 
highest Price and display their details.  
Create a structure to represent a product in an inventory. The structure should include: 
Product ID (integer) 
Product Name (string) 
Quantity (integer) 
Price (float) 
*/
//Four arrays, search for highest
#include <stdio.h>
#include <string.h>
void accept(int n, int id[], char na[][50], int q[], float p[])
{
    for (int i=0; i<n; i++)
    {
        printf("Enter details for product %d\n", i+1);
        printf("Product ID: ");
        scanf("%d", &id[i]);
        printf("Product Name: ");
        scanf("%s", na[i]);
        printf("Quantity: ");
        scanf("%d", &q[i]);
        printf("Price: ");
        scanf("%f", &p[i]);
    }
}
int highestQty(int n, int q[])
{
    int m=0;
    for (int i=1; i<n; i++)
    {
        if (q[i] > q[m])
            m=i;
    }
    return m;
}
int highestPrice(int n, float p[])
{
    int m=0;
    for (int i=1; i<n; i++)
    {
        if (p[i] > p[m])
            m=i;
    }
    return m;
}
void display(int n, int id[], char na[][50], int q[], float p[])
{
    float totalValue=0;
    for (int i=0; i<n; i++)
    {
        totalValue+=q[i]*p[i];
    }
    printf("Total inventory value: %f\n", totalValue);//could use %.2f for 2 decimal places
    int hq=highestQty(n, q);
    int hp=highestPrice(n, p);
    printf("Product with highest quantity:\nID: %d\nName: %s\nQuantity: %d\nPrice: %f\n", id[hq], na[hq], q[hq], p[hq]);
    printf("Product with highest price:\nID: %d\nName: %s\nQuantity: %d\nPrice: %f\n", id[hp], na[hp], q[hp], p[hp]);
}
int main(void)
{
    int n;
    printf("Enter number of products: ");
    scanf("%d", &n);
    int id[n], q[n];
    char na[n][50];
    float p[n];
    accept(n, id, na, q, p);
    display(n, id, na, q, p);
    return 0;
}