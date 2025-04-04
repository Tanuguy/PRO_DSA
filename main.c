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
};property;

//property = pro
void displaypro(property details[]);
//Search by nd
void bynd(property details[],char nh[]);
//Filter by price
void byprice(property details[],int price);

int main() {
    property details[area];
    {101,7500000,"Near City Center, Schools, Parks","Verified by Govt. Registry","OTP-based login"};
    {102,12000000,"Coastal Area, Hospitals, Malls","No hidden charges","Biometric login"};
    {103,9500000,"Suburban, Green Spaces, Markets","Tax-inclusive pricing","Email verification"};
    {104,6000000,"Industrial Zone, Transport Hubs","Transparent breakdown","Mobile number verification"};
    {105,25000000,"Luxury Area, Golf Course, Clubs","Clear contract terms","Two-factor authentication"};
    {106,8500000,"Riverside, Schools, Local Shops","Govt. certified rates","Password-protected login"};
    {107,17500000,"Hill Station, Resorts, Trails","No hidden fees","ace recognition"};

}

