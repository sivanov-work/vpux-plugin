<!-- Autogenerated by mlir-tblgen; don't manually edit -->
# OpInterface definitions
## NCEOpInterface (`VPU_NCEOpInterface`)

Base interface for VPU NCE Operations
### Methods:
#### `getKernelSize`

```c++
SmallVector<int64_t> getKernelSize();
```
Get NCE operation kernel size
NOTE: This method *must* be implemented by the user.

#### `getStrides`

```c++
SmallVector<int64_t> getStrides();
```
Get NCE operation kernel strides
NOTE: This method *must* be implemented by the user.

#### `getPad`

```c++
vpux::VPU::PaddingAttr getPad();
```
Get NCE operation padding
NOTE: This method *must* be implemented by the user.

#### `addWorkload`

```c++
mlir::Operation*addWorkload(mlir::OpBuilder&builder, mlir::Location loc, ShapeRef offsets, ShapeRef sizes, vpux::VPU::PaddingAttr pad, MPEMode mpeMode, mlir::IntegerAttr clusterId);
```
Add workload
NOTE: This method *must* be implemented by the user.

#### `workloads`

```c++
mlir::Region&workloads();
```
Get all workloads## SparseOpInterface (`VPU_SparseOpInterface`)

Interface for sparse operations
### Methods:
#### `sparsitySupport`

```c++
vpux::VPU::SparsitySupport sparsitySupport();
```
Marks the sparsity support for the inputs and outputs of an operation
NOTE: This method *must* be implemented by the user.
