<!-- Autogenerated by mlir-tblgen; don't manually edit -->
# AttributeInterface definitions
## TransformAttrInterface (`Const_TransformAttrInterface`)

The interface for Attributes, which holds information about lazy constant folding operation.

### Methods:
#### `inferOutputType`

```c++
vpux::NDTypeInterface inferOutputType(vpux::NDTypeInterface input);
```
Infer output type
NOTE: This method *must* be implemented by the user.

#### `transform`

```c++
vpux::Const::Content transform(vpux::Const::Content&input);
```
Transform the constant content
NOTE: This method *must* be implemented by the user.

#### `getTransformationName`

```c++
llvm::StringLiteral getTransformationName();
```
Get transformation name
NOTE: This method *must* be implemented by the user.

#### `getPositionRequirement`

```c++
vpux::Const::details::PositionRequirement getPositionRequirement();
```
Get transformation location requirement
NOTE: This method *must* be implemented by the user.

#### `updateAttributes`

```c++
Const::TransformAttrInterface updateAttributes(mlir::ElementsAttr&baseContent, ArrayRef<mlir::Attribute> prevTransformations);
```
Update attributes of transformation and return new one
NOTE: This method *must* be implemented by the user.

