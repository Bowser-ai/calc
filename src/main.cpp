#include "calc.h"

int main() {
	Calc_stream cs{std::cin};

	while(cs.is_ok()){
		try {
            std::cout<<prompt;
            double output =	declaration(cs);
            Token T = cs.get();
            
            switch (T.kind) {

                case  print_line:
                std::cout << output << std::endl;
                break;

                default: 
                cs.put_back(T);
                break;
                    }
                }
            catch (std::runtime_error&  e) {
                std::cout << e.what() << "\n";
                cs.clean();
                }
            }

	return 0;
}
