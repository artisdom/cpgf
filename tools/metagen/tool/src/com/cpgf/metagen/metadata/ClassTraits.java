package com.cpgf.metagen.metadata;

import java.util.List;

public class ClassTraits {
	private boolean isAbstract;
	private boolean destructorHidden;
	private boolean defaultConstructorHidden;
	private boolean copyConstructorHidden;

	public void getRules(List<String> rules) {
		if(this.isDestructorHidden()) {
			rules.add("GMetaRuleDestructorAbsent");
		}

		if(this.isDefaultConstructorHidden()) {
			rules.add("GMetaRuleDefaultConstructorAbsent");
		}
		
		if(this.isCopyConstructorHidden()) {
			rules.add("GMetaRuleCopyConstructorAbsent");
		}

		if(this.isAbstract()) {
			rules.add("GMetaRuleDefaultConstructorAbsent");
			rules.add("GMetaRuleCopyConstructorAbsent");
		}
	}

	public boolean isAbstract() {
		return isAbstract;
	}

	public void setAbstract(boolean isAbstract) {
		this.isAbstract = isAbstract;
	}

	public boolean isDestructorHidden() {
		return destructorHidden;
	}

	public void setDestructorHidden(boolean destructorHidden) {
		this.destructorHidden = destructorHidden;
	}

	public boolean isDefaultConstructorHidden() {
		return defaultConstructorHidden;
	}
	
	public void setDefaultConstructorHidden(boolean defaultConstructorHidden) {
		this.defaultConstructorHidden = defaultConstructorHidden;
	}
	
	public boolean isCopyConstructorHidden() {
		return copyConstructorHidden;
	}

	public void setCopyConstructorHidden(boolean copyConstructorHidden) {
		this.copyConstructorHidden = copyConstructorHidden;
	}

}