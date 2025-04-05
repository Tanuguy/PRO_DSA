#include <stdio.h>
#define area 30

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
//Search by nd
void bynd(property details[],char nh[]);
//Filter by price
void byprice(property details[],int price);

int main() {
    property details[area]={
        {101,7500000,"Near City Center Schools Parks","Verified by Govt. Registry","OTP-based login"},
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
    };

    int count = 20;
    printf("Data Property\n");
    displaypro(details,count);
    return 0;
}

void displaypro(property details[],int count) {
    printf("Property Details\n");
    for(int i=0;i<count;i++) {
        printf("Property ID:");
        printf("%d\t ",details[i].proID);
        printf("Price:");
        printf("%d\t",details[i].price);
        printf("Neighborhood:");
        printf("%s\t",details[i].nh);
        printf("Pricing Detials:");
        printf("%s\t",details[i].tpd);
        printf("Authentication Type:");
        printf("%s\t\n",details[i].at);
    }
}