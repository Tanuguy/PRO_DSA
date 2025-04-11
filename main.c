#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define area 25
#define money 10

typedef struct {
    //property ID = proid
    int proID;
    //Price
    int price;
    //City in which it is
    char city[100];
    // neighborhood = nh
    char nh[100];
    //pricing detail = tpd
    char tpd[100];
    //AuthenticationType = at
    char at[100];
}property;

typedef struct {
// Price range start
int ps;
//price range end
int pe;
}capital;

//property = pro
void displaypro(property details[],int count);
//Search by City
void citypro(property details[],int count,char city[]);
//Search by neighborhood
void bynd(property details[],int n,char nh[]);
//Filter by price
void byprice(property details[],int count,int mp);
//Fiter by Price Scope
void bytd(property details[],int count,char tpd[]);
//To display all Price ranges
void displayprice(capital pri[],int pr);


int main() {
    // All Data
    property details[area]={
        {101,7500000,"Dehradun","Near City Center, Schools, Parks","Verified by Govt. Registry","OTP-based login"},
        {102,12000000,"Rishikesh","Riverside, Hospitals, Malls","No hidden charges","Biometric login"},
        {103,9500000,"Almora","Suburban, Green Spaces, Markets","Tax-inclusive pricing","Email verification"},
        {104,6000000,"Haridwar","Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"},
        {105,25000000,"Mussoorie","Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"},
        {106,8500000,"Haridwar","Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"},
        {107,17500000,"Mussoorie","Hill Station, Resorts, Trails","No hidden fees","Face recognition"},
        {108,5000000,"Pauri Garhwal","Rural, Farms, Local Markets","Transparent pricing","OTP-based login"},
        {109,10000000,"Dehradun","Urban, IT Parks, Shopping Centers","Verified by Govt. Registry","Biometric login"},
        {110,15000000,"Haridwar","Riverside, Restaurants, Hotels","Tax-inclusive pricing","Email verification"},
        {111,7000000,"Mussoorie","Near Forest, Schools, Hospitals","Transparent breakdown","Mobile number verification"},
        {112,20000000,"Dehradun","Premium Area, Clubs, High-end Shops","Clear contract terms","Two-factor authentication"},
        {113,9000000,"Mussoorie","Near Forest, Trails, Resorts","Govt. certified rates","Password-protected login"},
        {114,12500000,"Haridwar","Near River, Parks, Schools","No hidden fees","Face recognition"},
        {115,5500000,"Bageshwar","Suburban, Green Spaces, Markets","Transparent pricing","OTP-based login"},
        {116,11000000,"Rishikesh","River Area, Hospitals, Malls","Verified by Govt. Registry","Biometric login"},
        {117,8000000,"Dehradun","Near City Center, Schools, Parks","Tax-inclusive pricing","Email verification"},
        {118,6500000,"Haridwar","Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"},
        {119,27500000,"Dehradun","Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"},
        {120,14000000,"Rishikesh","Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"},
        {121,18000000,"DehraDun","Mall, Forest","Govt. certified rates","Password-protected login"},
        {122,34000000,"Haridwar","Riverside","Govt. certified rates","Password-protected login"},
        {123, 25000000, "Rishikesh","River, Retreat", "Private Limited Rates", "Two-Factor Authentication"},
        {124, 20000000, "Mussoorie","Hill, Tourism", "Seasonal Offers", "Biometric Access"},
        {125, 22000000, "Haridwar","Temple, Pilgrimage", "Govt. Subsidized Packages", "Encrypted Login System"}
    };

    // Data of area rate
    capital pri[money]={
    {7500000,8000000},
    {11000000,12000000},
    {5500000,9500000},
    {6000000,6500000},
    {25000000,27500000},
    {8500000,14000000},
    {17500000,20000000},
    {5000000,7000000},
    };

    int choice;

        printf("What would you like to do?\n");
        printf("1. Display all Properties\n");
        printf("2. Search Property By Neighborhood\n");
        printf("3. Search Property By City\n");
        printf("4. Search Property By Price\n");
        printf("5. Search Property By Price Scope\n");
        printf("6. Display all Properties by Price Range\n");
        printf("7. Exit\n");

        printf("Enter you choice(1-6): ");
        scanf("%d",&choice);

        //Switich Statement
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
                char city[100];
                printf("Enter the City you are looking for:");
                scanf("%s",city);
                citypro(details,area,city);
                break;
            case 4:
                int mp;
                printf("Enter the Max Price in which you looking for:");
                scanf("%d",&mp);
                byprice(details,area,mp);
                break;
            case 5:
                char tpd[100];
                printf("Enter the Price Scope you are looking for:");
                scanf("%s",tpd);
                bytd(details,area,tpd);
                break;
            case 6:
                int pr = money;
                printf("Price Range\n");
                displayprice(pri,pr);
                break;
            case 7:
                printf("Thank you\nYour Dream Home is waiting for you\n");
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
        printf("City: %s\n", details[i].city);
        printf("Neighborhood: %s\n", details[i].nh);
        printf("Pricing Details: %s\n", details[i].tpd);
        printf("Authentication Type: %s\n", details[i].at);
        printf("------------------------------------\n\n\n");
    }
}

//Funtion to Search By City
void citypro(property details[],int count, char city[]) {
    int found = 0;
    for(int i=0;i<count;i++) {
        if(strstr(details[i].city,city)!=NULL){
            printf("Property ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("-------------------------------------\n\n\n");
            found = 1;
        }
    }
    if(!found) {
        printf("City not there\n");
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
            printf("City: %s\n", details[i].city);
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
            printf("City: %s\n", details[i].city);
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

void bytd(property details[],int count,char tpd[]) {
    int found = 0;
    printf("Searching for properties near: %s\n", tpd);
    for (int i = 0; i < count; i++) {
        if (strstr(details[i].tpd, tpd) != NULL) {
            printf("\nProperty ID: %d\n", details[i].proID);
            printf("Price: %d\n", details[i].price);
            printf("City: %s\n", details[i].city);
            printf("Neighborhood: %s\n", details[i].nh);
            printf("Pricing Details: %s\n", details[i].tpd);
            printf("Authentication Type: %s\n", details[i].at);
            printf("------------------------------------\n\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No properties found near: %s\n",tpd);
    }
}

void displayprice(capital pri[],int pr){
printf("Range Details\n");
for(int i=0;i<pr;i++){
    printf("Price Start: %d\n",pri[i].ps);
    printf("Price End:  %d\n",pri[i].pe);
    printf("-------------------------------------\n\n\n");
}
}


//......................
