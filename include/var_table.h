#include <string>
#include <unordered_map>

#ifndef VAR_TABLE_H_
#define VAR_TABLE_H_

class Var_table
{
	public:
		Var_table() {}

		double get_value(const std::string& name) const ;
		double set_value(const std::string& name, double value);
		bool is_declared(const std::string& name) const;

	private:
		std::unordered_map<std::string, double> var_table;
};

#endif
