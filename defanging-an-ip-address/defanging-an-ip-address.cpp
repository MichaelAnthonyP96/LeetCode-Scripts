class Solution {
public:
    string defangIPaddr(string address){
    size_t f = 0;
    int place = 0;
    do{
        f = address.substr(place,address.length()-place).find(".");
        if(f != std::string::npos){
            address.insert(f+place,"[");
            address.insert(f+place+2,"]");
            place = place + f + 2;
        }
        
    }while(f != std::string::npos);
    return address;
}
};