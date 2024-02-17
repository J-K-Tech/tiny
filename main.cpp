#include <sstream>
#include <string>
#include <fstream>
#include <map>
std::string get(std::string);
std::map<std::string,std::string> variables;

int call(
    std::string lines){
    std::string com;
    com.append("call");
    
    printf("command:%s\n\nexecuting\n\n\n",lines.c_str());
    com.append(lines.c_str());

    system(com.c_str());
    printf("\n\n\n");
    return 0;
}

int set(std::string setter){
    std::string name=setter.substr(setter.find_first_of(" ")+1,setter.find("=")-4);
    std::string value=setter.substr(setter.find("=")+1);
    variables[name.c_str()]=value.c_str();
    printf("key %s set as value %s\n\n",name.c_str(),value.c_str());
    //printf("\nvar: %s\n",variables[name].c_str());
}

std::string get(std::string key){
    std::string k=key.substr(key.find_first_of('%')+1,key.find_last_of('%')-1);
    std::string var=variables[k];
    if (var==""){
        printf("\ncould not get variable with key \"%s\"\n",k.c_str());
        exit(1);
    }
    //printf("\ngetting variable \"%s\" with key \"%s\"\n",var.c_str(),k.c_str());
    return var;
}

int main(int argc, char *argv[]){

    printf("tiny runner v0.5\n\n\n");
    std::fstream fileStream;
    fileStream.open(argv[1]);
    if (!fileStream.fail()){
    std::ifstream infile(argv[1]);
    std::string line;

    std::string lines;
    int mode=-1;
    while (std::getline(infile, line))
    {
        const char * l=line.c_str();
        if (line.length()!=0){
            switch (l[0])
            {
            case '\\':
                if (l[1]=='n'){
                    call(lines);
                    lines.clear();
                    break;}
                else{
                    lines.append(" "+line);
                }
            case '%':
                lines.append(get(line));
                break;

            case ';':
                break;
            case 's':
                if (l[1]=='e'&&l[2]=='t'){
                            call(lines);
                            lines.clear();
                            set(line);}
                else{
                lines.append(" "+line);

                }
                break;
                
                /* code */
            
            default:
                lines.append(" "+line);
                break;
            }
        }
        
    }
    call(lines);
    return 0;
    }
    printf("could not locate file %s",argv[1]);
    return 1;
}