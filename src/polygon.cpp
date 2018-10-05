#include <Rcpp.h>

#include "mapdeck.hpp"
#include "layers/polygon.hpp"
#include "parameters.hpp"

Rcpp::List polygon_defaults(int n) {
	return Rcpp::List::create(
		_["polyline"] = mapdeck::defaults::default_polyline(n),
		_["elevation"] = mapdeck::defaults::default_elevation(n),
		_["radius"] = mapdeck::defaults::default_radius(n),
		_["fill_colour"] = mapdeck::defaults::default_fill_colour(n),
		_["stroke_colour"] = mapdeck::defaults::default_stroke_colour(n)
	);
}


// [[Rcpp::export]]
Rcpp::StringVector rcpp_polygon( Rcpp::DataFrame data, Rcpp::List params ) {

	int data_rows = data.nrows();

	Rcpp::List lst_defaults = polygon_defaults( data_rows );  // initialise with defaults
	Rcpp::StringVector polygon_columns = mapdeck::polygon::polygon_columns;
	Rcpp::StringVector polygon_colours = mapdeck::polygon::polygon_colours;

	Rcpp::DataFrame df = mapdeck::parameters_to_data(
		data, params, lst_defaults, polygon_columns, polygon_colours, data_rows,
		true, true
	);

	return jsonify::dataframe::to_json( df );
}
