#ifndef VAR_TABLE_H_
#define VAR_TABLE_H_

#include <string>
#include <unordered_map>

class Var_table
{
	public:
		Var_table() {}

		double get_value(const std::string& name) const ;
		double set_value(const std::string& name, double value);
		bool is_declared(const std::string& name) const;
        double reassign(const std::string& name, double value);

	private:
		std::unordered_map<std::string, double> var_table;
};

#endif
