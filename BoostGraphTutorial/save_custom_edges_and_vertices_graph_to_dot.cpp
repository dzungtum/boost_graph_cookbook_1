#include "save_custom_edges_and_vertices_graph_to_dot.h"

#include "save_custom_edges_and_vertices_graph_to_dot_demo.impl"

#include <cassert>
#include <iostream>
#include <sstream>

#include "copy_file.h"
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "helper.h"
#include "is_regular_file.h"

void save_custom_edges_and_vertices_graph_to_dot_test() noexcept
{
  //Show it does store the vertex names
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();

    const std::string base_filename{"save_custom_edges_and_vertices_graph_to_dot_test"};
    const std::string dot_filename{base_filename + ".dot"};

    save_custom_edges_and_vertices_graph_to_dot(g,dot_filename);
    assert(is_regular_file(dot_filename));
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "digraph G {",
      "}"
    };
    assert(text != expected_text);
  }
  //Show it does not store the edges' names
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const std::string base_filename{"save_custom_edges_and_vertices_graph_to_dot_test"};
    const std::string dot_filename{base_filename + ".dot"};

    save_custom_edges_and_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=top];",
      "1[label=right];",
      "2[label=left];",
      "0--1 ;",
      "1--2 ;",
      "2--0 ;",
      "}"
    };
    assert(text != expected_text);
  }
  save_custom_edges_and_vertices_graph_to_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
