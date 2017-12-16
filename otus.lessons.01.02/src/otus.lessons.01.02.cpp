#include <iostream>

#include <spdlog/spdlog.h>

int main()
{
	auto console = spdlog::stdout_logger_mt("console");
	console->info("Wellcome to spdlog!");
	
	std::cout << "Hello World!" << std::endl;

	console->info("Goodbye spdlog!");
	getchar();
}
