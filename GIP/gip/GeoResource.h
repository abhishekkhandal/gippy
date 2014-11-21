/*##############################################################################
#    GIPPY: Geospatial Image Processing library for Python
#
#    Copyright (C) 2014 Matthew A Hanson
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program. If not, see <http://www.gnu.org/licenses/>
##############################################################################*/

#ifndef GIP_GEORESOURCE_H
#define GIP_GEORESOURCE_H

#include <string>
#include <gip/geometry.h>

namespace gip {
    using std::string:

    //! Base class representing a geospatial resource
    class GeoResource {
    public:
        //! \name Constructors
        //! Default Constructor with filename
        GeoResource(string filename = "");
        //! Copy constructor
        GeoResource(const GeoResource& resource);
        //! Assignment copy
        GeoResource& operator=(const GeoResource&);
        //! Destructor
        ~GeoResource() {};

        //! \name Resource Information
        //! Get the filename of the resource
        string Filename() const;
        //! Basename, or short name of filename
        string Basename() const;
        //! Format of resource
        virtual string Format() const;

        //! \name Geospatial information
        //! Width of resource
        virtual unsigned int XSize() const;
        //! Height of resource
        virtual unsigned int YSize() const;
        //! Geolocated coordinates of a point within the resource
        virtual Point<double> GeoLoc(float xloc, float yloc) const;
        //! Coordinates of top left
        Point<double> TopLeft() const;
        //! Coordinates of lower left
        Point<double> LowerLeft() const;
        //! Coordinates of top right
        Point<double> TopRight() const;
        //! Coordinates of bottom right
        Point<double> LowerRight() const;
        //! Minimum Coordinates of X and Y
        Point<double> MinXY() const;
        //! Maximum Coordinates of X and Y
        Point<double> MaxXY() const;
        //! Return projection definition in Well Known Text format
        virtual string Projection() const;
        //! Return projection as OGRSpatialReference
        OGRSpatialReference SRS() const;
        //! Get Affine transformation
        virtual CImg<double> Affine() const;

        //! \name Metadata functions
        //! Get metadata item
        string Meta(string key) const;
        // Get group of metadata
        //std::vector<std::string> GetMetaGroup(std::string group,std::string filter="") const;
        //! Set metadata item
        GeoResource& SetMeta(std::string key, std::string item);
        //! Set multiple metadata items
        GeoResource& SetMeta(std::map<std::string, std::string> items);
        //! Copy Meta data from another resource
        GeoResource& CopyMeta(const GeoResource& img);

    protected:
        //! Retrieve the GDALMajorObject from (GDALDataset, GDALRasterBand, OGRLayer)
        virtual GDALMajorObject* GDALMajorObject() const;

        //! Filename, or some other resource identifier
        boost::filesystem::path _Filename;

    }; // class GeoResource
} // namespace gip

#endif