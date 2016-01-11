#include "add_edge_between_two_selected_vertices_demo.impl"

#include "add_edge_between_two_selected_vertices.h"

#include <cassert>

#include "add_edge_between_two_selected_vertices.h"
#include "add_custom_and_selectable_vertex.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

void add_edge_between_two_selected_vertices_test() noexcept
{
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    add_custom_and_selectable_vertex(my_custom_vertex("Bert"),true, g);
    add_custom_and_selectable_vertex(my_custom_vertex("Ernie"),true, g);
    add_edge_between_two_selected_vertices(g);
    assert(boost::num_edges(g) == 1);
  }
  add_edge_between_two_selected_vertices_demo();
}
