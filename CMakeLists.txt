cmake_minimum_required(VERSION 3.7)
project(SEPtest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CalculateCustomers.cpp
        CalculateCustomers.h
        Command.cpp
        Command.h
        CommandBalance.cpp
        CommandBalance.h
        CommandBuy.cpp
        CommandBuy.h
        CommandEcho.cpp
        CommandEcho.h
        CommandPlay.cpp
        CommandPlay.h
        CommandQuit.cpp
        CommandQuit.h
        CommandQuote.cpp
        CommandQuote.h
        CommandRecipe.cpp
        CommandRecipe.h
        CommandSetweather.cpp
        CommandSetweather.h
        EnvironmentalCondition.cpp
        EnvironmentalCondition.h
        EnvironmentalEngine.cpp
        EnvironmentalEngine.h
        GameData.cpp
        GameData.h
        GameHandler.cpp
        GameHandler.h
        HTMLWriter.cpp
        HTMLWriter.h
        HTMLWriterBalance.cpp
        HTMLWriterBalance.h
        HTMLWriterEnvironment.cpp
        HTMLWriterEnvironment.h
        main.cpp
        UserInput.cpp
        UserInput.h)

add_executable(SEPtest ${SOURCE_FILES})