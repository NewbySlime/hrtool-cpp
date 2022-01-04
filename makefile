main:
ifndef InputF
	@echo "ERR: InputF not defined."
else ifndef srccpp
	@echo "ERR: srccpp not defined."
else ifndef OutputF
	@echo "ERR: OutputF not defined."
else
	g++ Handler.cpp $(srccpp) -o a.exe
	a.exe -i$(InputF) -o$(OutputF)
endif