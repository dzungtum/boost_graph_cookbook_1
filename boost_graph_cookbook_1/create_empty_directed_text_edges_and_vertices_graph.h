#ifndef CREATE_EMPTY_DIRECTED_TEXT_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_EMPTY_DIRECTED_TEXT_EDGES_AND_VERTICES_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, std::string,
  std::string>
create_empty_directed_text_edges_and_vertices_graph() noexcept;

#endif // CREATE_EMPTY_DIRECTED_TEXT_EDGES_AND_VERTICES_GRAPH_H
