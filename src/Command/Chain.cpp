#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include <algorithm>
#include <fstream>

namespace prog {
    namespace command {

        std::vector<std::string> Chain::hist;

        Chain::Chain(const std::vector<std::string>& file_list)
            : Command("chain"), files(file_list) {}

        Image* Chain::apply(Image* img) {
            for (size_t i = 0; i < files.size(); i++) {
                std::string file = files[i];

                // Verificar se o ficheiro já foi processado
                if (std::find(hist.begin(), hist.end(), file) != hist.end()) {
                    continue;
                }

                std::ifstream input(file);
                if (!input.is_open()) {
                    continue;
                }

                hist.push_back(file);

                ScrimParser parser;
                std::string name;

                while (input >> name) {
                    Command* cmd = parser.parse_command(name, input);
                    if (cmd == nullptr) continue;

                    std::string n = cmd->name();
                    if (n == "Save" || n == "Open" || n == "Blank") continue;

                    img = cmd->apply(img);
                }

                hist.pop_back();
            }

            return img;
        }
    }
}
