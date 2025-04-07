#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define area 22

typedef struct {
    //property ID = proid
    int proID;
    int price;
    // neighborhood = nh
    char nh[100];
    //pricing detail = tpd
    char tpd[100];
    //AuthenticationType = at
    char at[100];
}property;

//property = pro
void displaypro(property details[],int count);
//Search by neighborhood
void bynd(property details[],int n,char nh[]);
//Filter by price
void byprice(property details[],int count,int mp);


int main() {
    // All Data
    property details[area]={
        {101,7500000,"Near City Center, Schools, Parks","Verified by Govt. Registry","OTP-based login"},
        {102,12000000,"Coastal Area, Hospitals, Malls","No hidden charges","Biometric login"},
        {103,9500000,"Suburban, Green Spaces, Markets","Tax-inclusive pricing","Email verification"},
        {104,6000000,"Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"},
        {105,25000000,"Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"},
        {106,8500000,"Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"},
        {107,17500000,"Hill Station, Resorts, Trails","No hidden fees","Face recognition"},
        {108,5000000,"Rural, Farms, Local Markets","Transparent pricing","OTP-based login"},
        {109,10000000,"Urban, IT Parks, Shopping Centers","Verified by Govt. Registry","Biometric login"},
        {110,15000000,"Beachfront, Restaurants, Hotels","Tax-inclusive pricing","Email verification"},
        {111,7000000,"Near Metro, Schools, Hospitals","Transparent breakdown","Mobile number verification"},
        {112,20000000,"Premium Area, Clubs, High-end Shops","Clear contract terms","Two-factor authentication"},
        {113,9000000,"Near Forest, Trails, Resorts","Govt. certified rates","Password-protected login"},
        {114,12500000,"Near Lake, Parks, Schools","No hidden fees","Face recognition"},
        {115,5500000,"Suburban, Green Spaces, Markets","Transparent pricing","OTP-based login"},
        {116,11000000,"Coastal Area, Hospitals, Malls","Verified by Govt. Registry","Biometric login"},
        {117,8000000,"Near City Center, Schools, Parks","Tax-inclusive pricing","Email verification"},
        {118,6500000,"Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"},
        {119,27500000,"Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"},
        {120,14000000,"Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"},
        {121,18000000,"Mall","Govt. certified rates","Password-protected login"},
        {122,34000000,"Riverside","Govt. certified rates","Password-protected login"},
    };

    int choice;

        printf("What would you like to do?\n");
        printf("1. Display all Properties\n");
        printf("2. Search Property By Neighborhood\n");
        printf("3. Search Property By Price\n");
        printf("4. Exit\n");

        printf("Enter you choice(1-4): ");
        scanf("%d",&choice);

        //if Statement
        switch(choice) {
            case 1:
                int count = area;
                printf("Data Property\n");
                displaypro(details,count);
                break;
            case 2:
                int y = area;
                char nh[100];
                printf("Enter the neighborhood you are looking for:");
                scanf("%s",nh);
                bynd(details,y,nh);
                break;
            case 3:
                int mp;
                printf("Enter the Max Price in which you looking for:");
                scanf("%d",&mp);
                byprice(details,area,mp);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                break;
        }

return 0;
}

//Funtion to display all properties
void displaypro(property details[],int count) {
    printf("Property Details\n\n\n");
    for(int i=0;i<count;i++) {
        printf("\nProperty ID: %d\n", details[i].proID);
        printf("Price: %d\n", details[i].price);
        printf("Neighborhood: %s\n", details[i].nh);
        printf("Pricing Details: %s\n", details[i].tpd);
        printf("Authentication Type: %s\n", details[i].at);
        printf("------------------------------------\n\n\n");
    }
}

// Funtion to Search by neighborhood
void bynd(property details[], int n, char nh[]) {
    int found = 0;
    printf("Searching for properties near: %s\n", nh);
    for (int i = 0; i < n; i++) {
        if (strstr(details[i].nh, nh) != NULL) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n", nh);
    }
}

void byprice(property details[],int count,int mp){
    int found = 0;
    printf("Property under %d:\n",mp);
    for (int i = 0; i < count; i++) {
        if (details[i].price < mp) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("----------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No Properties found under %d:\n",mp);
    }
}

