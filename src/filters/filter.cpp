#include "../includes/filters/filter.h"
#include <map>

void ApplyFilters(Filters& filters, BitMap& bmp) {
    AgingFilter aging;
    BarrelDistortionFilter barrel;
    CropFilter crop;
    EdgeDetectionFilter edge;
    GaussianBlurFilter blur;
    GrayScaleFilter gs;
    NegativeFilter neg;
    PosterizationFilter poster;
    SepiaFilter sepia;
    SharpeningFilter sharp;

    std::map<std::string_view, BaseFilter*> pointers_to_filters;

    pointers_to_filters["-barrel"] = &barrel;
    pointers_to_filters["-blur"] = &blur;
    pointers_to_filters["-crop"] = &crop;
    pointers_to_filters["-edge"] = &edge;
    pointers_to_filters["-gs"] = &gs;
    pointers_to_filters["-neg"] = &neg;
    pointers_to_filters["-poster"] = &poster;
    pointers_to_filters["-sepia"] = &sepia;
    pointers_to_filters["-sharp"] = &sharp;
    pointers_to_filters["-age"] = &aging;

    for (const Filter& filter : filters) {
        TestFilterParameters(filter);
        pointers_to_filters[filter.filter_name]->Apply(filter.filter_params, bmp);
    }
}
