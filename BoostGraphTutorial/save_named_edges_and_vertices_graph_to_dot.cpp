#include "save_named_edges_and_vertices_graph_to_dot.h"

#include <cassert>
#include <iostream>
#include <sstream>

#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "helper.h"

void save_named_edges_and_vertices_graph_to_dot_test() noexcept
{
  //Show it stores the edges' names
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::string base_filename{"save_named_edges_and_vertices_graph_to_dot_test_named_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_named_edges_and_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=top];",
      "1[label=right];",
      "2[label=left];",
      "0--1 [label=\"AB\"];",
      "1--2 [label=\"BC\"];",
      "2--0 [label=\"CA\"];",
      "}"
    };
    assert(text == expected_text);
  }
  std::cout << __func__ << ": OK" << '\n';
}
