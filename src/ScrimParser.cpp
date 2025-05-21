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
#include "Command/h_mirror.hpp"
#include "Command/v_mirror.hpp"
#include "Command/Fill.hpp"
#include "Command/Slide.hpp"
#include "Command/crop.hpp"
#include "Command/Resize.hpp"
#include "Command/rotate_left.hpp"
#include "Command/rotate_right.hpp"
#include "Command/Scaleup.hpp"
#include "Command/add.hpp"

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

        if (command_name == "h_mirror") {
            return new command::h_mirror();
        }
        if (command_name == "v_mirror") {
            return new command::v_mirror();
        }

        if (command_name == "fill") {
            int x,y,w,h;
            int r_, g_, b_;
            input>>x>>y>>w>>h>>r_>>g_>>b_;
            rgb_value r = rgb_value(r_);
            rgb_value g = rgb_value(g_);
            rgb_value b = rgb_value(b_);


            return new command::Fill(x,y,w,h,r,g,b);
        }

        if (command_name == "slide") {
            int xs, ys;

            input >>xs>>ys;

            return new command::Slide(xs,ys);

        }


        if (command_name == "crop") {
            int x,y,w,h;
            input >> x >> y >> w >> h;
            return new command::crop(x,y,w,h);
        }

        if (command_name == "resize") {
            int x,y,w,h;
            input >> x >> y >> w >> h;
            return new command::Resize(x,y,w,h);
        }

        if (command_name == "rotate_left") {
            return new command::rotate_left();
        }

        if (command_name == "rotate_right") {
            return new command::rotate_right();
        }

        if (command_name == "scaleup") {
            int x,y;
            input >> x >> y;
            return new command::Scaleup(x,y);
        }

        if (command_name == "add") {
            std::string filename;
            int r_, g_, b_;
            int x,y;
            input>>filename>>r_>>g_>>b_>>x>>y;
            rgb_value r = rgb_value(r_);
            rgb_value g = rgb_value(g_);
            rgb_value b = rgb_value(b_);
            return new command::add(filename,r,g,b,x,y);
        }

        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
