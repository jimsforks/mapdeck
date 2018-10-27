#include <Rcpp.h>

#include "mapdeck.hpp"
#include "layers/scatterplot.hpp"
#include "parameters.hpp"

Rcpp::List scatterplot_defaults(int n) {
	return Rcpp::List::create(
		_["polyline"] = mapdeck::defaults::default_polyline(n),
		_["radius"] = mapdeck::defaults::default_radius(n),
		_["fill_colour"] = mapdeck::defaults::default_fill_colour(n)
	);
}


// [[Rcpp::export]]
Rcpp::List rcpp_scatterplot_geo( Rcpp::DataFrame data, Rcpp::List params ) {

	int data_rows = data.nrows();

	Rcpp::List lst_defaults = scatterplot_defaults( data_rows );  // initialise with defaults
	Rcpp::StringVector scatterplot_columns = mapdeck::scatterplot::scatterplot_columns;
	std::map< std::string, std::string > scatterplot_colours = mapdeck::scatterplot::scatterplot_colours;
	Rcpp::StringVector scatterplot_legend = mapdeck::scatterplot::scatterplot_legend;

	return create_data(
		data, params, lst_defaults,
		scatterplot_columns, scatterplot_colours, scatterplot_legend,
		data_rows
	);
}


