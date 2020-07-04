#include "var_table.h"

Var_table::Var_table()
{
	// Some named constants
	set_value("PI", 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825, true);
}

double Var_table::get_value(const std::string& name) const
{
	try{
		return var_table.at(name).get_value();
	}
	catch (std::out_of_range& e)
	{
		throw std::runtime_error{"definition does not exist, please use the let declaration\n"};
	}
}

double Var_table::set_value(const std::string& name, double value, bool is_const)
{
	if (!is_declared(name))
	{
		var_table.insert(std::pair<std::string, Variable>{name, Variable{name, value, is_const}});
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
        Variable& var = var_table.at(name);
		if (var.get_is_const()) throw std::runtime_error{"cannot reassign const variable\n"};
		var.set_value(value);
        return value;
    }
    catch (std::out_of_range& e)
    {
        throw std::runtime_error{name + " not defined, please use the 'let' declaration\n"};
    }
}
