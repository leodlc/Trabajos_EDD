/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#include <string>
#include <functional>
#include <vector>

class MenuItem {
public:
	MenuItem() = default;
	MenuItem(
		std::string label,
		std::function<void()> action = [] {},
		bool must_wait = true,
		bool is_enabled = true);
	MenuItem(
		std::function<std::string()> label,
		std::function<void()> action = [] {},
		bool must_wait = true,
		bool is_enabled = true);

	MenuItem& enabled(bool value);
	MenuItem& enabled(std::function<bool()> callable);
	MenuItem& wait(bool value);
	MenuItem& wait(std::function<bool()> callable);
	MenuItem& action(std::function<void()> callback);

	void label(std::string label);

    std::string label();
    bool is_enabled();
	bool must_wait();
    void exec();

private:
	std::function<std::string()> label_ = [] { return "[unamed]"; };
	std::function<bool()> must_wait_ = [] { return true; };
	std::function<bool()> is_enabled_ = [] { return true; };
    std::function<void()> action_ = []{};
};

class Menu {
public:
    Menu(std::string title = "Menu");
    void add(MenuItem option);
    void run();
	void stop();
	MenuItem exit_item(std::string label = "Exit");

private:
	bool running_ = false;
    std::string title_;
    std::vector<MenuItem> items_;
};
