#include "var_table.h"

double Var_table::get_value(const std::string& name) const
{
	try{
		return var_table.at(name);
	}
	catch (std::out_of_range& e)
	{
		throw std::runtime_error{"definition does not exist, please use the let declaration\n"};
	}
}

double Var_table::set_value(const std::string& name, double value)
{
	if (!is_declared(name))
	{
		var_table[name] = value;
	}
	else throw std::runtime_error{name + " is already defined\n"};
	return value;
}

bool Var_table::is_declared(const std::string& name) const
{
	return var_table.find(name) != var_table.cend();
}

double Var_table::reassign(const std::string& name, double value)
{
    try
    {
        double& val = var_table.at(name);
        val = value;
        return val;
    }
    catch (std::out_of_range& e)
    {
        throw std::runtime_error{name + " not defined, please use the 'let' declaration\n"};
    }
}
