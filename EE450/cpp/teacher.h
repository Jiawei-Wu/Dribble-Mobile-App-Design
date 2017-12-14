#include<string>
using namespace std;

class teacher{
        private:
                string name;
                string gender;
                int age;
        public:
                void setName(string _name);
                string getName();
                void setGender(string _gender);
                string getGender();
                void setAge(int _age);
                int getAge();
                void teach();
};

