module;

import types;

export module polygon;

export class IPolygon {
public:
	virtual byte_t degree() const = 0;
	virtual ~IPolygon() { }
};

export class Triangle : IPolygon {
public:
	virtual byte_t degree() const override;
};
