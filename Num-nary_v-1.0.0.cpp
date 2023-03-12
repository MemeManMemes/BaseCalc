#include <iostream>
#include <vector>

std::vector<std::string> w_rizz(std::vector<std::string> w, uint64_t j, uint64_t f,uint64_t g, int y, int vals)
{
	while (f < j)
    {
        f *= vals;
        y++;
    }

    for (int i = 0; i < y + 1; i++)
    {
		bool jj = false;
        for (int ii = vals - 1; ii > 0; ii--)
        {
			if (j >= f * ii)
			{
				w.push_back(std::to_string(ii));
				jj = true;
				j -= f * ii;
			}
		}
        if (!jj) w.push_back("0");
        f /= vals;
    }
    return w;
}

int main()
{
	//Example program
	int vals = 2;
	std::cout << "Enter the amount of values: ";
	std::cin >> vals;
	std::cout << "Enter a number: ";
    uint64_t j = 0, f = 1, g = 0;
    int y = 0;
    std::cin >> g;
    j = g;
    
    std::vector<std::string> w;
    std::string r = "";
	w = w_rizz(w, j, f, g, y, vals);
    
    f = 1;
    y = 0;
    j = g;
    
    while (f < j)
    {
		f *= 2;
		y++;
	}
    
    for (int i = 0; i < y + 1; i++)
    {
		if (j >= f)
        {
			r += "1";
            j -= f;
        }
        else r += "0";
        f /= 2;
	}
	
    std::cout << "In binary " << g << " is ";
    for (int i = 0; i < int(r.length()); i++) std::cout << r[i] << " ";
    
    std::cout << std::endl << "While in " << vals << "-nary " << g << " is ";
    
    for (int i = 0; i < int(w.size()); i++) std::cout << w[i] << " ";
    
    std::cout << std::endl << std::endl << "This means that " << vals << "-nary is " << r.length() - w.size() << " digits more efficient than binary in this case";
	
    return 0;
}
