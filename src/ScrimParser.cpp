//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Logger.hpp"
#include "Command/Invert.hpp"
#include "Command/Gray_scale.hpp"
#include "Command/Replace.hpp"
#include "Command/Move.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>



using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        if (command_name == "invert") {
            return new command::Invert();

        }

        if (command_name == "to_gray_scale") {
            return new command::Gray_scale();

        }

        if (command_name == "replace") {
            int r1_, g1_, b1_, r2_, g2_, b2_;
            input>>r1_>>g1_>>b1_>>r2_>>g2_>>b2_;
            rgb_value r1 = rgb_value(r1_);
            rgb_value g1 = rgb_value(g1_);
            rgb_value b1 = rgb_value(b1_);
            rgb_value r2 = rgb_value(r2_);
            rgb_value g2 = rgb_value(g2_);
            rgb_value b2 = rgb_value(b2_);
            return new command::Replace(r1, g1, b1, r2, g2, b2);

        }

        if (command_name == "move") {
            int xm, ym;

            input >>xm>>ym;

            return new command::Move(xm,ym);

        }


        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
