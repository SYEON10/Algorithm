select child.ID as ID, child.GENOTYPE as GENOTYPE, parent.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA as child, ECOLI_DATA as parent
where parent.ID = child.PARENT_ID and child.GENOTYPE & parent.GENOTYPE >= parent.GENOTYPE
order by child.ID