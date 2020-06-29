#include "calc.h"

int main() {
	while(std::cin){
		
		try {
            std::cout<<prompt;
            double output =	declaration();
            Token T = Cs.get();
            
            switch (T.kind) {

                case  print_line:
                std::cout << output << std::endl;
                break;

                default: 
                Cs.put_back(T);
                break;
                    }
                }
            catch (std::runtime_error&  e) {
                std::cout << e.what() << "\n";
                Cs.clean();
                }
            }

return 0;
}


